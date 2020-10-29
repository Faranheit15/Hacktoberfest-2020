<!DOCTYPE html>
<html>
<head>
<title>LuXe</title>
</head>
<link rel="icon" type="image/png" href="images/logo.png">
<link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
<script type="text/javascript">
	setTimeout(function(){
		var user_check_val = document.getElementById('user_check').innerText;
		var usertype_check_val = document.getElementById('usertype_check').innerText;
		
	    if(user_check_val == "null"){
	      	window.location.href = "login.jsp";
	    }
	    else{
	    	if(usertype_check_val == "owner"){
	    		window.location.href = "owner/home.jsp";
	    	}
	    	else if(usertype_check_val == "manager"){
	    		window.location.href = "manager/home.jsp";
	    	}
	    	else{
	    		window.location.href = "user/home.jsp";
	    	}
	    }
         }, 2500);
</script>
<style type="text/css">
.img_cls {
	top: 50%;
	left: 50%;
	position: absolute;
	transform: translate(-50%, -50%);
	padding: 30px;
	border-radius: 50%;
}

.loading_img {
	top: 60%;
	left: 50%;
	position: absolute;
	transform: translate(-50%, -50%);
	width: 300px;
	height: 25px;
}
</style>

<body>

	<img src="images/logo_white.png" class="w3-blue img_cls" style="">

	<img src="images/hhh.png" class="loading_img">

	<p id="user_check" style="display: none;"><%= session.getAttribute( "LogedInUserName" ) %></p>
	<p id="usertype_check" style="display: none;"><%= session.getAttribute( "LogedInUserType" ) %></p>

</body>

</html>
