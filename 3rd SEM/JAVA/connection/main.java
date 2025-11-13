// File: main.java


import java.sql.*;

public class main {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/javaDB"; 
        String username = "root"; 
        String password = "";     
        try {
           
            Class.forName("com.mysql.cj.jdbc.Driver");

            Connection conn = DriverManager.getConnection(url, username, password);
            Statement stat=conn.createStatement();
            ResultSet rs=stat.executeQuery("SELECT * FROM student");

            while (rs.next()) { 
                int id =rs.getInt("id");
                int grade=rs.getInt("grade");
                String name=rs.getString("name");
                System.out.println("id"+id+"grade"+grade+"name"+name);
            }

            rs.close();
            stat.close();
            conn.close();
        } catch (ClassNotFoundException e) {
            System.out.println("MySQL JDBC driver not found.");
            e.printStackTrace();
        } catch (SQLException e) {
            System.out.println("Connection failed!");
            System.out.println("Error: " + e.getMessage());
        }
    }
}
