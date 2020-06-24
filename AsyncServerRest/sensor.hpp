#define DHTPIN 2

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void initSensor(){
  dht.begin();
}

float leerTemperatura(){
  return dht.readTemperature();
}

float leerHumedad(){
  return dht.readHumidity(); 
}
