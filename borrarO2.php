<html>
<head>
 <title>borrarO2.php</title>
 <center><img src="uam.jpg"></center>
</head>
<body>
 <?php
 $enlace = mysqli_connect("localhost","root","find your own way");//Conexion a BD
 mysqli_select_db($enlace,"oferta_curso");
 $Del= $_POST["Oferta"];
 $ssql="DELETE from oferta WHERE fecha_curso=$Del";
 $resul = mysqli_query($enlace,$ssql);
 if(! $resul )
{
 die('Error ' . mysql_error());
}
mysqli_close($enlace);
 ?>
 <h1><div align="center">Registro Eliminado</h1></div>
 <div align="center">
 <a href="oferta.php">Visualizar la tabla "oferta"</a></div>
</body>
</html>