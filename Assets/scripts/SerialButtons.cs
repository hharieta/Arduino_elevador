using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
public class SerialButtons : MonoBehaviour
{
    SerialPort arduinoPort = new SerialPort("/dev/ttyACM0");

    private void Awake()
    {
        arduinoPort.BaudRate = 9600;
        arduinoPort.Parity = Parity.None;
        arduinoPort.StopBits = StopBits.One;
        arduinoPort.DataBits = 8;
        arduinoPort.Handshake = Handshake.None;
    }
    // Start is called before the first frame update
    void Start()
    {
        arduinoPort.Open();        
    }

    public void SendMessageToArduino( string message)
    {
        arduinoPort.WriteLine(message);
    }

    public void ClosePort()
    {
        arduinoPort.Close();
    }
}