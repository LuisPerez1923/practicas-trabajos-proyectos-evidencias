<html>
<head>
 <title>insertarEE2.php</title>
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
 $numero = $_POST ['empno'];
 $cargo = $_POST ['job'];
 $rfc = $_POST ['rfc'];
 $nombre = $_POST ['ename'];
 $apellido = $_POST ['lastname'];
 $fecha = $_POST ['nacimiento'];
 $resultado = mysqli_query($enlace, "INSERT INTO empleado(idempleado,cargo,RFC,nombre,apellido,fecha_nac) VALUES
($numero,'$cargo','$rfc','$nombre','$apellido','$fecha')");
if(! $resultado )
{
 die('No se pudo insertar los datos: ' . mysql_error());
}
mysqli_close($enlace);
 ?>
 <h1><Div align="center">Registro insertado</div></h1>
 <center><a href="empleado2.php">Visualizar contenido de empleados </a></center>
</body>
</html>