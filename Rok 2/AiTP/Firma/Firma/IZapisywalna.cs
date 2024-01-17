using System.Runtime.Serialization.Formatters.Binary;

namespace Firma;

public interface IZapisywalna
{
    void ZapiszBin(string nazwa);
    Object OdczytajBin(string nazwa);
}