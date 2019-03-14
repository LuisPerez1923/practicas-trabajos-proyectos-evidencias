<html>
<head>
 <title>insertarOE2.php</title>
 <center><img src="uam.jpg"></center>
</head>
<body>
 <?php
 $servername = "localhost";
 $username = "root";
 $password = "find your own way";
 $dbname = "oferta_curso";
 $enlace = mysqli_connect($servername,$username,$password);//Conexion a BD
if(!$enlace){
die("Conexion fallida: " . mysql_error())."\n";
}
else{
echo "Conexion exitosa<br>";
}
 mysqli_select_db($enlace,"oferta_curso");
 $num = $_POST ['empno'];
 $fecha = $_POST ['fechacur'];
 $califi = $_POST ['calif'];
 $resultado = mysqli_query($enlace, "INSERT INTO oferta_empleado(idempleado,fecha_curso,calificacion) VALUES
($num,$fecha,$califi)");
if(! $resultado )
{
 die('No se pudo insertar los datos: ' . mysql_error());
}
mysqli_close($enlace);
 ?>
 <h1><Div align="center">Registro insertado</div></h1>
 <center><a href="ofertaempleado.php">Visualizar contenido de las ofertas de los empleados</a></center>
</body>
</html>