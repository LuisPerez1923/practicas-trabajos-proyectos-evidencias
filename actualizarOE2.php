<html>
<head>
 <title>actualizarOE2.php</title>
 <center><img src="uam.jpg"></center>
</head>
<body>
 <div align = "center"><h1>Actualizar un registro</h1><br>
 <?php
 $servername = "localhost";
 $username = "root";
 $password = "find your own way";
 $dbname = "oferta_curso";
 $enlace = mysqli_connect($servername,$username,$password);//Conexion a BD
mysqli_select_db($enlace, "oferta_curso");
 $numero = $_POST ['oferta_empleado'];
 $fecha = $_POST ['fechacur'];
 $califi = $_POST ['calif'];
 $ssql="UPDATE oferta_empleado SET fecha_curso='$fecha',calificacion='$califi' WHERE idempleado='$numero'";

 $res=mysqli_query($enlace,$ssql);
if(! $res )
{
 die('Informacion no actualizada: ' . mysql_error());
}
mysqli_close($enlace);
 ?>
 <h2><div align ="center">Registro Actualizado</div></h2>
 <a href="ofertaempleado.php"><center>Visualizar el contenido de la tabla
 de Curso</center></a>
</body>
</html>