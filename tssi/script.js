let title = document.querySelector("title");

let hasFocus = () =>{
    if(document.hasFocus()){
        title.textContent = "Dokument";
    }
    else{
        title.textContent = "Wróc, proszę 😥";
    }
}
setInterval(hasFocus, 300);