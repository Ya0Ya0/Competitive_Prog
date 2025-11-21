package java;
public class Empleado{
    public Empleado jefe;
    public String nombre;
    public void setNombre(String nombre)
    {
        this.nombre = nombre;
    }
    public String getNombre()
    {
        return nombre;
    } 
    public void setJefe(Empleado jefe)
    {
        this.jefe = jefe;
    }
    public Empleado getJefe()
    {
        return jefe;
    } 
    public Empleado(String nombre, Empleado jefe)
    {
        setJefe(jefe);
        setNombre(nombre);
    }
}