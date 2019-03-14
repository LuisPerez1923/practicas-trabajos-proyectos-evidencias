<html>
<head>
 <title>actualizarC1.php</title>
 <center><img src="uam.jpg"></center>
</head>
<body>
 <div align = "center"><h1>Actualizar 1 registro</h1>

 <form method="post" Action="actualizarC2.php">

 <?php
echo "Curso";
 ?>


<select name="curso">
<br><br>

<?php
 $servername = "localhost";
 $username = "root";
 $password = "find your own way";
 $dbname = "oferta_curso";
 $enlace = mysqli_connect($servername,$username,$password);//Conexion a BD

 mysqli_select_db($enlace,$dbname); //conexion con la bd

 echo "Curso<br>";

 $ssql="SELECT idcurso FROM curso ORDER BY idcurso";

 $resultado=mysqli_query($enlace, $ssql);

 while ($renglon=mysqli_fetch_array($resultado))
 {
    echo "<option>".$renglon[0]."</option>";
 }

?>

 </select>
 <br>
 Nombre del curso<br>
 <Input type="Text" name="nombrecur"><br>
 Horas del curso<br>
 <Input type="Text" name="horas"><br><br>
 <Input type="submit" value="actualizar">
 </form>
 </div>
</body>
</html>