public abstract class Employee {

    private String Name;
    private int ID;

    public Employee(String name, int id) {
        this.ID = id;
        this.Name = name;
    }

    // Setter
    public void setID(int iD) {
        ID = iD;
    }

    public void setName(String name) {
        Name = name;
    }

    // Getter
    public int getID() {
        return ID;
    }

    public String getName() {
        return Name;
    }

    public abstract double calculateSalary();

    @Override
    public String toString() {
        return "ID: " + ID + ", Name: " + Name;
    }
}

// SalaryEmployee class
class PermanentEmployee extends Employee {

    private double Salary;

    public PermanentEmployee(int id, String name, double salary) {
        super(name, id);
        this.Salary = salary;
    }

    public void setSalary(float salary) {
        this.Salary = salary;
    }

    public double getSalary() {
        return Salary;
    }

    public double calculateSalary() {
        return getSalary();
    }

    @Override
    public String toString() {
        return super.toString();
    }
}

// HourlyEmployee class
class HourlyEmployee extends Employee {

    private double wage; // wage per hour
    private double hours;// hours worked for week

    public HourlyEmployee(int id, String name, double hours, double wage) {
        super(name, id);
        this.setHours(hours);
        this.setWage(wage);
    }

    // Getter
    public double getWage() {
        return wage;
    }

    public void setWage(double hourlyWage) {
        if (hourlyWage >= 0.0) {
            this.wage = hourlyWage;
        } else
            throw new IllegalArgumentException("HourLY Wage must be >=0.0");
    }

    public double getHours() {
        return hours;
    }

    public void setHours(double hourWorked) {
        if (hourWorked >= 0.0) {
            this.hours = hourWorked;
        } else
            throw new IllegalArgumentException("Hour must be >=0.0 and <=168"); // work hour per week 7*24hrs
    }

    public double calculateSalary() {
        if (getHours() <= 40) {
            return getWage() * getHours();
        } else {
            return getWage() * getHours() + (getHours() - 40) * getWage() * 1.5;
        }
    }

    @Override
    public String toString() {
        return super.toString() + ", hourly wage: " + getWage() + ", hours worked: " + getHours();
    }

}

class SalariedCommissionEmployee extends Employee {

    private double baseSalary;
    private double grossSales;
    private double commissionRate;

    public SalariedCommissionEmployee(int id, String name, double sales, double rate, double salary) {
        super(name, id);
        this.setBaseSalary(salary);
        this.setCommissionRate(rate);
        this.setGrossSales(sales);
    }

    public double getBaseSalary() {
        return baseSalary;
    }

    public void setBaseSalary(double salary) {
        if (salary >= 0.0) {
            this.baseSalary = salary;
        } else
            throw new IllegalArgumentException("Base salary must be >0.0");
    }

    public double getGrossSales() {
        return grossSales;
    }

    public void setGrossSales(double sales) {
        if (sales >= 0.0) {
            this.grossSales = sales;
        } else
            throw new IllegalArgumentException("gross sales must be > 0.0");
    }

    public double getCommissionRate() {
        return commissionRate;
    }

    public void setCommissionRate(double rate) {
        if (rate > 0.0 && rate < 1.0) {
            this.commissionRate = rate;
        } else
            throw new IllegalArgumentException("Commission rate must be > 0 and < 1.0");
    }

    @Override
    public double calculateSalary() {

        return getBaseSalary() + getGrossSales() * getCommissionRate();
    }

    @Override
    public String toString() {
        return super.toString() + ", gross sales: " + getGrossSales() + ", commission rate: " + getCommissionRate()
                + ", base salary: " + getBaseSalary();
    }

}

// Company.java
import java.util.ArrayList;

public class Company {

    private String Name;
    private ArrayList<Employee> employee;

    public Company(String name, ArrayList<Employee> e) {
        this.Name = name;
        this.employee = e;
    }

    public void addEmployee(Employee e) {
        employee.add(e);
    }

    public void CalculateSalary() {
        for (int i = 0; i < employee.size(); i++) {
            System.out
                    .println(employee.get(i) + ", Salary: " + String.format("%.2f", employee.get(i).calculateSalary()));
        }
    }

    public void giveIncrement(double percentage) {
        for (int i = 0; i < employee.size(); i++) {
            System.out.println(employee.get(i) + ", Salary: " + String.format("%.2f",
                    employee.get(i).calculateSalary() + employee.get(i).calculateSalary() * percentage));
        }
    }

}

class Test {
    public static void main(String[] args) {

        // create four-element Employee array
        Employee[] employees = new Employee[5];

        // initialize array with Employees
        employees[0] = new PermanentEmployee(101, "Archangel Macsika", 680000.00);
        employees[1] = new HourlyEmployee(201, "Nsikak", 17.00, 9000);
        employees[2] = new SalariedCommissionEmployee(305, "John Doe", 9100000, 0.04, 590000);
        employees[3] = new HourlyEmployee(202, "Nsikak", 17.00, 9000);
        employees[4] = new SalariedCommissionEmployee(302, "Rose Maryland", 2120000, .03, 600000);

        ArrayList<Employee> list = new ArrayList<Employee>();
        list.add(employees[0]);
        list.add(employees[1]);
        list.add(employees[2]);
        list.add(employees[3]);
        list.add(employees[4]);
        Company c = new Company("My Company", list);
        // before increment salary
        System.out.println("\nBefore increment salary");
        c.CalculateSalary();

        // After increment salary
        System.out.println("\nAfter increment salary");
        c.giveIncrement(0.1);
    }
}


