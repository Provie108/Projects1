

function validate() {
	
	if(document.regForm.lastname.value == ""){
		document.getElementById("lastnameMessage").innerHTML = "(First Name Cant be Blank!!)";
		return false;
	}

		else if(document.regForm.firstname.value == ""){
		document.getElementById("firstnameMessage").innerHTML = "(First Name Cant be Blank!!)";
		return false;
	}
	
	return true;
}