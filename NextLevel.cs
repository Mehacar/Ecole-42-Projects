using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class NextLevel : MonoBehaviour
{
    [SerializeField] private float GecisSuresi;
    private Scene _scene;

    private void Awake()
    {
        _scene = SceneManager.GetActiveScene();
    }

    IEnumerator DelayTime()
    {
        yield return new WaitForSeconds(GecisSuresi); // wait 2 secounts from unity
        Debug.Log("2sn beklendi");
        SceneManager.LoadScene(_scene.buildIndex + 1);
    }

    private void OnTriggerEnter2D(Collider2D other)
    {
        if (other.gameObject.CompareTag("Player"))
        {
                 StartCoroutine(DelayTime());
        }
    }

    public void StartLevel()
    {
        if (_scene.buildIndex == 3 )
            SceneManager.LoadScene(_scene.buildIndex - 3); // For restart button
        else
            SceneManager.LoadScene(_scene.buildIndex + 1);
    }

    public void GameOverLevel()
    {
        if (score.lives == 0)
        {
            //Debug.Log("scorelives : " + score.lives);
            score.lives = 3; 
            SceneManager.LoadScene(0);
        }
    }
    
    
}
