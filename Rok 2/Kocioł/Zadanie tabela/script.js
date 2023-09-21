let button_yes = document.getElementById("yes")
let button_no = document.getElementById("no")
let solve = document.getElementById("solve")
solve.addEventListener("click", ()=>{  
    solve.style.display = 'none';
    button_yes.style.display = 'block';
    button_no.style.display = 'block';
})
let answers = [1,3,1,4,0,1,0,2,0,2,1,0,3,0,0]
let change_answers = document.querySelectorAll(".answer")
let grupa = document.getElementById("grupa")
let imie = document.getElementById("name")
button_yes.addEventListener("click", ()=>{
    for (let i = 0; i<15; i++){
        change_answers[i].innerHTML = answers[i]
    }
    button_yes.style.display = "none"
    button_no.style.display = "none"
    grupa.innerHTML = "2P2"
    imie.innerHTML = "Kozub Bartosz"
})
button_no.addEventListener("click",()=>{
    solve.style.display = 'block';
    button_yes.style.display = 'none';
    button_no.style.display = 'none';
})


