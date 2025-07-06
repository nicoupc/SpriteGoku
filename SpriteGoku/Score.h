#pragma once
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

public ref class Score {
public:
    String^ nombre;
    DateTime fecha;
    int porcentaje;
    int tiempoSegundos;

    Score(String^ nombre, DateTime fecha, int porcentaje, int tiempoSegundos) {
        this->nombre = nombre;
        this->fecha = fecha;
        this->porcentaje = porcentaje;
        this->tiempoSegundos = tiempoSegundos;
    }

    // Guardar un solo score en binario
    void guardar(BinaryWriter^ writer) {
        writer->Write(nombre);
        writer->Write(fecha.ToBinary());
        writer->Write(porcentaje);
        writer->Write(tiempoSegundos);
    }

    // Leer un solo score desde binario
    static Score^ leer(BinaryReader^ reader) {
        String^ nombre = reader->ReadString();
        DateTime fecha = DateTime::FromBinary(reader->ReadInt64());
        int porcentaje = reader->ReadInt32();
        int tiempo = reader->ReadInt32();
        return gcnew Score(nombre, fecha, porcentaje, tiempo);
    }

    // Leer todos los scores desde el archivo
    static List<Score^>^ cargarTodos(String^ ruta) {
        List<Score^>^ lista = gcnew List<Score^>();
        if (!File::Exists(ruta)) return lista;

        FileStream^ fs = File::Open(ruta, FileMode::Open);
        BinaryReader^ reader = gcnew BinaryReader(fs);

        try {
            while (fs->Position < fs->Length) {
                Score^ s = Score::leer(reader);
                lista->Add(s);
            }
        }
        finally {
            reader->Close();
            fs->Close();
        }

        return lista;
    }

    // Guardar todos los scores en el archivo
    static void guardarTodos(String^ ruta, List<Score^>^ lista) {
        FileStream^ fs = File::Open(ruta, FileMode::Create);
        BinaryWriter^ writer = gcnew BinaryWriter(fs);

        for each (Score ^ s in lista) {
            s->guardar(writer);
        }

        writer->Close();
        fs->Close();
    }

    // Ordenar por porcentaje descendente y tiempo ascendente
    static int CompararScores(Score^ a, Score^ b) {
        if (a->porcentaje != b->porcentaje)
            return b->porcentaje.CompareTo(a->porcentaje); // Más plataformas primero
        else
            return a->tiempoSegundos.CompareTo(b->tiempoSegundos); // Menor tiempo primero
    }

    static void ordenar(List<Score^>^ lista) {
        lista->Sort(gcnew Comparison<Score^>(&Score::CompararScores));
    }
};
