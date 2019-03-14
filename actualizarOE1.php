<html>
<head>
 <title>actualizarOE1.php</title>
 <center><img src="uam.jpg"></center>
</head>
<body>
 <div align = "center"><h1>Actualizar 1 registro</h1>

 <form method="post" Action="actualizarOE2.php">

 <?php
echo "Num. emp";
 ?>


<select name="calificacion">
<br><br>

<?php
 $servername = "localhost";
 $username = "root";
 $password = "find your own way";
 $dbname = "oferta_curso";
 $enlace = mysqli_connect($servername,$username,$password);//Conexion a BD

 mysqli_select_db($enlace,$dbname); //conexion con la bd

 echo "Calificacion<br>";

 $ssql="SELECT idempleado,fecha_curso FROM oferta_empleado ORDER BY idempleado,fecha_curso";

 $resultado=mysqli_query($enlace, $ssql);

 while ($renglon=mysqli_fetch_array($resultado))
 {
 echo"<option>".$renglon[0]."&nbsp &nbsp".$renglon[1]."</option>";
 }

?>

 </select>
 <br>
 Fecha del curso<br>
 <Input type="Text" name="fechacur"><br>
 Calificacion<br>
 <Input type="Text" name="calif"><br><br>
 <Input type="submit" value="actualizar">
 </form>
 </div>
</body>
</html>