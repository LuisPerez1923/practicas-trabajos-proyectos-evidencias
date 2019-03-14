<html>
<head>
 <title>borrarC2.php</title>
 <center><img src="uam.jpg"></center>
</head>
<body>
 <?php
 $enlace = mysqli_connect("localhost","root","find your own way");//Conexion a BD
 mysqli_select_db($enlace,"oferta_curso");
 $cur= $_POST["Curso"];
 $ssql="DELETE from curso WHERE idcurso=$cur";
 $resul = mysqli_query($enlace,$ssql);
 if(! $resul )
{
 die('Error ' . mysql_error());
}
mysqli_close($enlace);
 ?>
 <h1><div align="center">Registro Eliminado</h1></div>
 <div align="center">
 <a href="curso.php">Visualizar la tabla de curso</a></div>
</body>
</html>