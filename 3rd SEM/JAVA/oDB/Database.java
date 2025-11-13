package src;
import java.sql.*;


public class  {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/javaDB"; // Change "testdb" to your DB name
        String user = "root";
        String password = "ishaninsql"; // XAMPP default has no password

        try {
            Connection conn = DriverManager.getConnection(url, user, password);
            System.out.println("Connected to database successfully!");
            conn.close();
        } catch (SQLException e) {
            System.out.println("Database connection failed!");
            e.printStackTrace();
        }
    }
}