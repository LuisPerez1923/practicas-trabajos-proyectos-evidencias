<html>
<head>
 <title>borrarEE2.php</title>
 <center><img src="uam.jpg"></center>
</head>
<body>
 <?php
 $enlace = mysqli_connect("localhost","root","find your own way");//Conexion a BD
 mysqli_select_db($enlace,"oferta_curso");
 $emp= $_POST["Empleado"];
 $ssql="DELETE FROM empleado WHERE idempleado=$emp";
 $resul = mysqli_query($enlace,$ssql);
 if(! $resul )
{
 die('Error ' . mysql_error());
}
mysqli_close($enlace);
 ?>
 <h1><div align="center">Registro Eliminado</h1></div>
 <div align="center">
 <a href="empleado2.php">Visualizar la tabla "empleados"</a></div>
</body>
</html>