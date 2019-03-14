<html>
<head>
 <title>actualizarO1.php</title>
 <center><img src="uam.jpg"></center>
</head>
<body>
 <div align = "center"><h1>Actualizar 1 registro</h1>

 <form method="post" Action="actualizarO2.php">

 <?php
echo "Oferta";
 ?>


<select name="oferta">
<br><br>

<?php
 $servername = "localhost";
 $username = "root";
 $password = "find your own way";
 $dbname = "oferta_curso";
 $enlace = mysqli_connect($servername,$username,$password);//Conexion a BD

 mysqli_select_db($enlace,$dbname); //conexion con la bd

 echo "Oferta<br>";

 $ssql="SELECT fecha_curso FROM oferta ORDER BY fecha_curso";

 $resultado=mysqli_query($enlace, $ssql);

 while ($renglon=mysqli_fetch_array($resultado))
 {
    echo "<option>".$renglon[0]."</option>";
 }

?>

 </select>
 <br>
 Salon<br>
 <Input type="Text" name="salon"><br>
 Clave de curso<br>
 <Input type="Text" name="curso"><br>
 Num. emp<br>
 <Input type="Text" name="empno"><br><br>


 <Input type="submit" value="actualizar">
 </form>
 </div>
</body>
</html>