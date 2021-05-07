import java.sql.*;
import java.util.Enumeration;

public class DatabaseServic {
    public static void main(String[] args) throws SQLException {
        String url = "jdbc:mysql://localhost:3306/address_book_service";
        String username = "root";
        String password = "Kartik@123";
        Connection connection = null;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection = DriverManager.getConnection(url, username, password);
            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery(" select * from addressbook");
            ResultSetMetaData resultSetMetaData = resultSet.getMetaData();
            while (resultSet.next()) {
                for (int i = 1; i <= resultSetMetaData.getColumnCount(); i++) {
                    if (i > 1) System.out.print(",  ");
                    String columnValue = resultSet.getString(i);
                    System.out.print(columnValue + " " + resultSetMetaData.getColumnName(i));
                }
                System.out.println();
            }
//            while (resultSet.next()) {
//                System.out.print(resultSet.getInt("sr_no"));
//                System.out.println(resultSet.getString("first_name"));
//                System.out.println(resultSet.getString("last_name"));
//            }
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        finally {
            if (connection != null) {
                connection.close();
            }
        }
    }
}