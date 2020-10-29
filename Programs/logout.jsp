<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>

</head>
<body>
<p id="usertype_check" style="display: none;"><%=session.getAttribute("LogedInUserType")%></p>
</body>
<script type="text/javascript">
	var usertype_check_val = document.getElementById('usertype_check').innerText;
	var action = confirm("Are you sure you want to log out?");

	if (action == true) {
		window.location.href = "login.jsp";
	} else {
		if (usertype_check_val == "admin") {
			window.location.href = "admin/home.jsp";
		} else {
			window.location.href = "user/home.jsp";
		}
	}
</script>

</html>
