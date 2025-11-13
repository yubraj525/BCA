

// question no 9
const alpha=['apple','b','c','d','e']
const caps=alpha.map((letter)=> letter.toLocaleUpperCase())
console.log(caps)

// question 10
const books=[
    {name:"science",author:"yubraj"},
        {name:"math",author:"ishan"},
            {name:"commerce",author:"bipin"}
]
const newarr=books.splice(1,1);
console.log(books)

//question 11
const string=["hello","bye","hi","good","alaram" ,"apple"];
string.sort();
console.log(string);

//question 12
const filterdA=string.filter((a)=>a.startsWith('a',0))
console.log(filterdA);

// question 13
const details=[
    {name:"ishan",age:12},
     {name:"biin",age:0},
     {name:"ruksan",age:99}

]

const onlyage=details.map(a=> a.age)
console.log(onlyage);