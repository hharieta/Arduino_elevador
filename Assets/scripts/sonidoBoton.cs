using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class sonidoBoton : MonoBehaviour
{
    public AudioSource fuente;
    public AudioClip clip;
    // Start is called before the first frame update
    void Start()
    {
        fuente.clip = clip;
        
    }

    public void Reproducir()
    {
        fuente.Play();
    }
}
