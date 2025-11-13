const task=[];
const addTaskBtn=document.getElementById('addTaskBtn');
const taskInput=document.getElementById('taskInput');
const taskList=document.getElementById('content');
addTaskBtn.addEventListener('click',()=>{
    const taskText=taskInput.value
    if(taskText!==''){
        const newTask={
            id:task.length+1,
            text:taskText,
            completed:false
        };
        task.push(newTask);
        ShowTask();
        taskInput.value='';
    }
});

function ShowTask(){
    task.forEach((taskItem)=>{
        taskList.innerHTML+=`
        <tr class="task-item">
           <td> ${taskItem.id}</td>
            <td class="${taskItem.completed ?'notcompleted':''}">${taskItem.text}</>
            <td ><button onclick='toggledone(${taskItem.text})'>Done</button></td>
        `;  

    }
    );
}
function toggledone(text){
    console.log(text);
    const taskItem=task.find((item)=>item.text===text);
  console.log(taskItem);
    alert("task completed");

}
