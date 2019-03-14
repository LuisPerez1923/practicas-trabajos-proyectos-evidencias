<html>
<head>
 <title>borrarC1.php</title>
 <center><img src="uam.jpg"></center>
</head>
<body>
 <div align="center">
 <h1>Borrar un registro</h1><br>
 <form method="post" Action = "borrarC2.php">Curso<br>
 <select name="Curso">
 <br><br>
 <?php
 $servername = "localhost";
 $username = "root";
 $password = "find your own way";
 $dbname = "oferta_curso";
 $enlace = mysqli_connect($servername,$username,$password);//Conexion a BD
 mysqli_select_db($enlace,$dbname); //conexion con la bd

 $ssql="SELECT idcurso FROM curso ORDER BY idcurso";
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