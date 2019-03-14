<html>
<head>
 <title>borrarOE1.php</title>
 <center><img src="uam.jpg"></center>
</head>
<body>
 <div align="center">
 <h1>Borrar un registro</h1><br>
 <form method="post" Action = "borrarOE2.php">Num. emp. y fecha de curso<br>
 <select name="Empleado">
 <br><br>
 <?php
 $servername = "localhost";
 $username = "root";
 $password = "find your own way";
 $dbname = "oferta_curso";
 $enlace = mysqli_connect($servername,$username,$password);//Conexion a BD
 mysqli_select_db($enlace,$dbname); //conexion con la bd

 $ssql="SELECT idempleado FROM oferta_empleado ORDER BY idempleado";
 $resultado=mysqli_query($enlace,$ssql);

 while($renglon=mysqli_fetch_array($resultado))
 {
 echo"<option>".$renglon[0]."</option>";
 }
 mysqli_free_result($resultado);
 ?>

 </select><br>
 <input type="submit" value="Eliminar">
 </form>
 </div>
</body>
</html>

<select name="Fecha">
 <br><br>
 <?php
$ssql="SELECT fecha_curso FROM oferta_empleado ORDER BY fecha_curso";
 $resultado=mysqli_query($enlace,$ssql);

 while($renglon=mysqli_fetch_array($resultado))
 {
 echo"<option>".$renglon[0]."</option>";
 }
 mysqli_free_result($resultado);
 ?>

 </select><br>
 <input type="submit" value="Eliminar">
 </form>
 </div>
</body>
</html>