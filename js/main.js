const buttonMenu = document.getElementById("buttonMenu");
const buttonClose = document.getElementById("buttonClose");
const menu = document.getElementById("menu");

function showMenu(){
    menu.style.display = "flex";
    buttonMenu.style.display = "none";
    buttonClose.style.display = "block";
}

function hideMenu(){
    menu.style.display = "none";
    buttonMenu.style.display = "block";
    buttonClose.style.display = "none";
}

const buttonMenu2 = document.getElementById("buttonMenu2");
const buttonClose2 = document.getElementById("buttonClose2");
const menuTeam = document.getElementById("menuTeam");

function showMenuTeam(){
    menu.style.display = "flex";
    buttonMenu.style.display = "none";
    buttonClose.style.display = "block";
}

function hideMenuTeam(){
    menu.style.display = "none";
    buttonMenu.style.display = "block";
    buttonClose.style.display = "none";
}

const page1 = document.getElementsByClassName("page1");
const page2 = document.getElementsByClassName("page2");
// const page3 = document.getElementsByClassName("page3");

const button1 = document.getElementById("button1");
const button2 = document.getElementById("button2");
// const button3 = document.getElementById("button3");

const counter = document.getElementById("counter");

function showPage1(){
    for(let i = 0; i < page1.length; i++){
        page1[i].style.display = "block";
        page2[i].style.display = "none";
        // page3[i].style.display = "none";
        button1.style.background = "white"
        button2.style.background = "none"
        // button3.style.background = "none"
    }
    counter.innerHTML = "1";
};

function showPage2(){
    for(let i = 0; i < page1.length; i++){
        page1[i].style.display = "none";
        page2[i].style.display = "block";
        // page3[i].style.display = "none";
        button1.style.background = "none"
        button2.style.background = "white"
        // button3.style.background = "none"
    }

    counter.innerHTML = "2";
};

// function showPage3(){
//     for(let i = 0; i < page1.length; i++){
//         page1[i].style.display = "none";
//         page2[i].style.display = "none";
//         page3[i].style.display = "block";
//         button1.style.background = "none"
//         button2.style.background = "none"
//         button3.style.background = "white"
//     }

//     counter.innerHTML = "3";
// };
const team = document.getElementById("team");
const modalContainer = document.getElementById("modalContainer");

function showModal(name) {
    var modalname = name;
    modalname.style.display = "block";
    modalContainer.style.display = "flex";
    team.style.display = "none";
}
  
function closeModal(name) {
    // When the user clicks on <span> (x), close the modal
    var modalname = name;
    modalname.style.display = "none";
    modalContainer.style.display = "none";
    team.style.display = "flex";
};