// function prime(num) {
//     let isPrime = true;
//     for (let j = 2; j < num; j++) {
//         if (num % j == 0) {

//             isPrime = false
//             break;
//         }


//     }

//     if (isPrime) {

//         console.log(`${num} is a prime`)
//     }


// }
// for (let i = 0; i < 100; i++) {
//     prime(i)
// }




// to find string rev

// function StringRev(text) {
  
//     console.log(text.length)
//         text.slice(0,-1)
//     console.log(text)
// }
// StringRev("hello");



const arr=["zero","one","two","three"]
for(let key of arr){
    console.log(key);
}

for(i=0;i<arr.length-1;i++){
    console.log(arr[i]);
}

console.log(arr.toString());87