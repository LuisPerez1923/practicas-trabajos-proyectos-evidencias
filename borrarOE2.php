<html>
<head>
 <title>borrarOE2.php</title>
 <center><img src="uam.jpg"></center>
</head>
<body>
 <?php
 $enlace = mysqli_connect("localhost","root","find your own way");//Conexion a BD
 mysqli_select_db($enlace,"oferta_curso");
 $Del= $_POST["Calificacion"];
 $ssql="DELETE from oferta_empledo WHERE idempleado=$Del";
 $resul = mysqli_query($enlace,$ssql);
 if(! $resul )
{
 die('Error ' . mysql_error());
}
mysqli_close($enlace);
 ?>
 <h1><div align="center">Registro Eliminado</h1></div>
 <div align="center">
 <a href="ofertaempleado.php">Visualizar la tabla "oferta"</a></div>
</body>
</html>