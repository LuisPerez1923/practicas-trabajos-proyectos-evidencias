<html>
<head>
 <title>actualizarEE1.php</title>
 <center><img src="uam.jpg"></center>
</head>
<body>
 <div align = "center"><h1>Actualizar 1 registro</h1>

 <form method="post" Action="actualizarEE2.php">

 <?php
echo "Empleado";
 ?>


<select name="empleado">
<br><br>

<?php
 $servername = "localhost";
 $username = "root";
 $password = "find your own way";
 $dbname = "oferta_curso";
 $enlace = mysqli_connect($servername,$username,$password);//Conexion a BD

 mysqli_select_db($enlace,$dbname); //conexion con la bd

 echo "Empleado<br>";

 $ssql="SELECT idempleado FROM empleado ORDER BY idempleado";

 $resultado=mysqli_query($enlace, $ssql);

 while ($renglon=mysqli_fetch_array($resultado))
 {
    echo "<option>".$renglon[0]."</option>";
 }

?>

 </select>
 <br>
 Cargo<br>
 <Input type="Text" name="job"><br>
 RFC<br>
 <Input type="Text" name="rfc"><br>
 Nombre<br>
 <Input type="Text" name="ename"><br>
 Apellido<br>
 <Input type="Text" name="lastname"><br>
 Fecha nac.<br>
 <Input type="Text" name="nacimiento"><br><br>



 <Input type="submit" value="actualizar">
 </form>
 </div>
</body>
</html>