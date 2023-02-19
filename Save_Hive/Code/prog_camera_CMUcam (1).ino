#include <CMUcam4.h>

// Initialisation de la caméra
CMUcam4 cam;

void setup() {
  Serial.begin(9600);
  // Ouverture de la communication avec la caméra sur le port série 1
  cam.begin(1);
}

void loop() {
  // Lecture de la trame de la caméra
  cam.readFrame();
  
  // Détection de la couleur jaune
  int color = cam.findColor(RED);
  
  // Si la couleur est détectée, affichage de la position de la couleur sur le moniteur série
  if(color != -1) {
    Serial.print("A hornet is detected.");
    Serial.println(cam.colorX);
  }
  
  // Attente de 100 ms avant de lire une nouvelle trame
  delay(100);
}
