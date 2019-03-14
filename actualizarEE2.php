<html>
<head>
 <title>actualizarEE2.php</title>
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

 $numero = $_POST ['empleado'];
 $cargo = $_POST ['job'];
 $rfc = $_POST ['rfc'];
 $nombre = $_POST ['ename'];
 $apellido = $_POST ['lastname'];
 $fecha = $_POST ['nacimiento'];
 $ssql="UPDATE empleado SET cargo='$cargo',RFC='$rfc',nombre='$nombre',apellido='$apellido',fecha_nac='$fecha' WHERE idempleado=$numero";

 $res=mysqli_query($enlace,$ssql);
if(! $res )
{
 die('Informacion no actualizada: ' . mysql_error());
}
mysqli_close($enlace);
 ?>
 <h2><div align ="center">Registro Actualizado</div></h2>
 <a href="empleado2.php"><center>Visualizar el contenido de la tabla
 de Curso</center></a>
</body>
</html>