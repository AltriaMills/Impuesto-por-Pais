using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace impuesto_por_pais
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double costobasico, impuesto, preciototal;
            Console.WriteLine("Ingrese el valor del costo basico");
            costobasico = Convert.ToDouble(Console.ReadLine());
            impuesto = 0;
            if (costobasico >= 20 && costobasico < 40)
            {
                impuesto = costobasico * 0.3;
            }
            else if (costobasico >= 40 && costobasico <= 500)
            {
                impuesto = costobasico * 0.4;
            }
            else if (costobasico > 500)
            {
                impuesto = costobasico * 0.5;

            }
            preciototal = costobasico + impuesto;
            Console.WriteLine("Impuesto que se esta aplicando: " + impuesto);
            Console.WriteLine("El precio total es de: " + preciototal);
            Console.ReadKey();
        }

     }
}
