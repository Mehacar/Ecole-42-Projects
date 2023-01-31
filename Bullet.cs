using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Collections.Generic;

public class Bullet : MonoBehaviour
{
    
    public GameObject bulletPrefab;
    //public float lifetime = 1f; // added a public variable for the bullet's lifetime
    private void OnTriggerEnter2D(Collider2D other)
    {
        
        
        if (other.gameObject.CompareTag("Enemy")) // check if the collider is the enemy
        {
            other.GetComponentInChildren<LifeBar>().life -= 5f; //LifeBar.life -= 5f;
            Destroy(bulletPrefab); //Destroy(bulletPrefab, lifetime); // destroy the bullet after a set amount of time
        }
    }
    
    
    
}
