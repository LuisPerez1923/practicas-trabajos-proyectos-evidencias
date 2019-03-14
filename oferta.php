<html>
<head>
 	<title>oferta.php</title>
 	<center><img src="uam.jpg"></center>
</head>

<body>
 	<h1><div align="center">Lectura de la tabla</div></h1>
	 <br>
 <?php 
		//Conexion con la base de datos
 		$enlace = mysqli_connect ("localhost","root","find your own way"); //conexion a mysql
 		if(!$enlace){
			die("Conexion fallida: " . mysql_error());
		}
		else{
			echo "Conexion exitosa";
		}
 		mysqli_select_db($enlace,"oferta_curso"); //conexion con la bd
 		$resultado=mysqli_query($enlace,"SELECT * FROM oferta" );
 	?>
<br>
<table align="center" border=1>
 <tr>
 	<th>Fecha de curso</th>
	 <th>Salon</th>
 	<th>Clave de curso</th>
         <th>Num. empleado</th>
	
        
 </tr>

<?php 
	//Mostrar los registros

	 while($row=mysqli_fetch_array($resultado,MYSQLI_BOTH))
 	{
 	echo "<tr><td>".$row[0]."</td>"."<td>".$row[1]."</td>"."<td>".$row[2]."</td>"."<td>".$row[3]."</td></tr>";
	 }
 	echo "</table>";
 mysqli_free_result($resultado);
?>
 <br><br>
 <div align="center">
 <a href="insertarO1.php">Anadir un nuevo registro</a><br>
 <a href="actualizarO1.php">Actualizar un registro </a><br>
 <a href="borrarO1.php">Borrar un registro</a></br>
 </div>
</Body>
</html>