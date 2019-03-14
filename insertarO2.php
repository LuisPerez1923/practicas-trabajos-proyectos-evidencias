<html>

<head>

 <title>insertarO2.php</title>
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

 $fechacur = $_POST ['fechacur'];
 $salon = $_POST ['salon'];
 $curso = $_POST ['curso'];
 $empno = $_POST ['empno'];
 $resultado = mysqli_query($enlace, "INSERT INTO oferta(fecha_curso,salon,idcurso,idempleado) VALUES
('$fechacur','$salon',$curso,$empno)");

if(! $resultado )
{
 die('No se pudo insertar los datos: ' . mysql_error());
}

mysqli_close($enlace);
 ?>
 <h1><Div align="center">Registro insertado</div></h1>
 <center><a href="oferta.php">Visualizar contenido de las ofertas</a></center>
</body>
</html>