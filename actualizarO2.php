<html>
<head>
 <title>actualizarO2.php</title>
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
 $fechacur = $_POST ['oferta'];
 $salon = $_POST ['salon'];
 $curso = $_POST ['curso'];
 $empno = $_POST ['empno'];
 $ssql="UPDATE oferta SET salon='$salon',idcurso='$curso',idempleado='$empno' WHERE fecha_curso=$fechacur";

 $res=mysqli_query($enlace,$ssql);
if(! $res )
{
 die('Informacion no actualizada: ' . mysql_error());
}
mysqli_close($enlace);
 ?>
 <h2><div align ="center">Registro Actualizado</div></h2>
 <a href="oferta.php"><center>Visualizar el contenido de la tabla
 de oferta</center></a>
</body>
</html>