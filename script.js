

const userInput = document.getElementById(`queryInfo`);
const dataDiv = document.getElementById(`table`)

async function submitClick() {
    const id = userInput.value;
    console.log(id);

    const datas = await fetch(`user/${id}`)


    const dataRow = await datas.json();
    console.log(dataRow);
    dataDiv.textContent = JSON.stringify(dataRow, null, 4);

}


 // .then(console.log('fetched'))
                        // .then(response=>{ return response.json()})
                        // .then(data=>{
                        //     data.forEach(element => {
                        //         const title = element.STUDENT_ID;
                        //         dataDiv.insertAdjacentHTML("beforeend",title);
                        //     });
                        //     return data;
                        // })
                        // .catch((err)=>{
                        //     console.log(err);
                        // })