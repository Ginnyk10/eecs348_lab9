function validate() {
    var password1 = document.getElementById("password1").value;
    var password2 = document.getElementById("password2").value;


    if (password1.length < 8) {
        alert("First password's length is less than 8 letters! Try Again.")
    } else if (password2.length < 8) {
        alert("Second password's length is less than 8 letters! Try Again")
    } else if (password1 != password2) {
        alert("Two passwords don't match!")
    } else {
        alert("Valid Passwords")
    }
}

var picture_index = 0;

function prev() {
    picture_index = ((picture_index + 5) - 1) % 5
    var picture_uri = `pictures/${picture_index}.jpeg`
    document.getElementById("picture").src = picture_uri
}

function next() {
    picture_index = (picture_index + 1) % 5
    var picture_uri = `pictures/${picture_index}.jpeg`
    document.getElementById("picture").src = picture_uri
}

function alert_paragraph_color() {
    var border_Red = document.getElementById("border_Red").value;
    var border_Green = document.getElementById("border_Green").value;
    var border_Blue = document.getElementById("border_Blue").value;
    var border_width = document.getElementById("border_width").value;
    var bg_Red = document.getElementById("bg_Red").value;
    var bg_Green = document.getElementById("bg_Green").value;
    var bg_Blue = document.getElementById("bg_Blue").value;

    var tag = document.getElementById("paragraph");
    tag.style.borderColor = `rgb(${border_Red},${border_Green},${border_Blue})`;
    tag.style.borderWidth = border_width
    tag.style.backgroundColor = `rgb(${bg_Red},${bg_Green},${bg_Blue})`;
}
