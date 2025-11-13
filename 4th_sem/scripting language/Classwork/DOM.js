const btn=document.getElementById("btn");
const btn2=document.getElementById("btn2");
const title=document.getElementById("title");

btn2.addEventListener("click",()=>{
    title.innerHTML="<p> Document Object Model </p>";
    title.classList.toggle("title");
    title.innerHTML.text="<p> Document Object Model </p>";
})