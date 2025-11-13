const task = [];
const addTaskBtn = document.getElementById('addTaskBtn');
const taskInput = document.getElementById('taskInput');
const taskList = document.getElementById('content');
const clearall = document.getElementById('clearall');

addTaskBtn.addEventListener('click', () => {
    const taskText = taskInput.value
    if (taskText !== '') {
        const newTask = {
            id: task.length + 1,
            text: taskText,
            completed: false
        };
        task.push(newTask);
        ShowTask();
        taskInput.value = '';
    }
});

clearall.addEventListener('click', () => {
    task.forEach((taskItem) => {
        if (!taskItem.completed) {
            taskItem.completed = true;
        }
        else {
            taskItem.completed = false;
        }
        ShowTask();
    });
});

    function ShowTask() {
        taskList.innerHTML = ``
        task.forEach((taskItem) => {
            taskList.innerHTML += `
        <tr class="task-item">
           <td> ${taskItem.id}</td>
            <td  style="color: ${taskItem.completed ? 'green' : 'red'};">${taskItem.text}</>
            <td >
            <button onclick='togglestate(${taskItem.id})'>
            ${taskItem.completed ? 'Undo' : 'Done'}
            </button>
            </td>
        `;

        }
        );
    }
    function togglestate(id) {
        console.log(id);
        const taskItem = task.find((item) => item.id === id);
        taskItem.completed = !taskItem.completed;
        console.log(taskItem);

        ShowTask();
      

    }

