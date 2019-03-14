<html>
<head>
 <title>actualizarC2.php</title>
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
 $curso= $_POST ['curso'];
 $nombrecur = $_POST ['nombrecur'];
 $horas = $_POST ['horas'];
 $ssql="UPDATE curso SET nombre_cur='$nombrecur',num_horas='$horas' WHERE idcurso=$curso";

 $res=mysqli_query($enlace,$ssql);
if(! $res )
{
 die('Informacion no actualizada: ' . mysql_error());
}
mysqli_close($enlace);
 ?>
 <h2><div align ="center">Registro Actualizado</div></h2>
 <a href="curso.php"><center>Visualizar el contenido de la tabla
 de Curso</center></a>
</body>
</html>