using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class Salir : MonoBehaviour
{
    SerialPort arduinoPort = new SerialPort("/dev/ttyACM0");
    
    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.Escape))
        {
            Application.Quit();
            Debug.Log("Has been exited");
        }
    }

    public void QuitGame()
    {
        Application.Quit();
        Debug.Log("Has been exited...");
    }
}