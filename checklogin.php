
<?php
session_start();
?>

<?php
$servername = "localhost";
$username = "root";
$password = "find your own way";
$db_name = "oferta_curso";
$tbl_name = "usuarios";
$conexion = mysqli_connect($servername,$username,$password);//Conexion a BD
mysqli_select_db($conexion, "oferta_curso");

if ($conexion->connect_error) {
 die("La conexion falló: " . $conexion->connect_error);
}
 
$userid = $_POST['userid'];
$password = $_POST['password'];
  
$sql = "SELECT * FROM usuarios WHERE numero_usuario = $userid";
$result = mysqli_query($conexion,$sql);

if ($result->num_rows > 0) {     
 }
 $row = $result->fetch_array(MYSQLI_ASSOC);
 if (password_verify($password, $row['password'])) { 
    $_SESSION['loggedin'] = true;
    $_SESSION['userid'] = $userid;
    $_SESSION['start'] = time();
    $_SESSION['expire'] = $_SESSION['start'] + (5 * 60);
    echo "Bienvenido! " . $_SESSION['userid'];
    echo "<br><br><a href=paginaprincipal2.html>Panel de Control</a>"; 
 } else { 

   echo "Numero de usuario o contrasena estan incorrectos."; 
   echo "<br><a href='login.html'>Volver a Intentarlo</a>";
        }
 mysqli_close($conexion); 
 ?>