<html>
<head>
 <title>insertarC2.php</title>
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
 $curso= $_POST ['curso'];
 $nombrecur = $_POST ['nombrecur'];
 $horas = $_POST ['horas'];
 $resultado = mysqli_query($enlace, "INSERT INTO curso(idcurso,nombre_cur,num_horas) VALUES
($curso,'$nombrecur','$horas')");
if(! $resultado )
{
 die('No se pudo insertar los datos: ' . mysql_error());
}
mysqli_close($enlace);
 ?>
 <h1><Div align="center">Registro insertado</div></h1>
 <center><a href="curso.php">Visualizar contenido del curso</a></center>
</body>