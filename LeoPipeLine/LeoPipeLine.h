struct Pipe;
struct Station;

void PrintMenu();

void PrintPipeEdit();

void PrintStationEdit();

void PipeEdit(int b, Pipe& pipe);

void StationEdit(int c, Station& station);

void LoadFromFile(Pipe& pipe, Station& station);

void OutputInFile(Pipe& pipe, Station& station);
