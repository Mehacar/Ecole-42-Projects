using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TankMovement : MonoBehaviour
{
    /*
    public float speed = 2.0f;
    public string enemyTag = "Enemy";

    void Update()
    {
        
        GameObject enemy = GameObject.FindWithTag(enemyTag);
        if (enemy != null)
        {
            Vector3 newPosition = transform.position;
            newPosition.x = Mathf.Lerp(transform.position.x, enemy.transform.position.x, Time.deltaTime * speed);
            transform.position = newPosition;
        }
    }*/
    /*
    public float speed = 2.0f;
    private GameObject enemy;
    void OnTriggerEnter2D(Collider2D other)
    {
        if (other.CompareTag("Enemy"))
        {
            enemy = other.gameObject;
        }
    }

    void Update()
    {
        if (enemy != null)
        {
            Vector3 newPosition = transform.position;
            newPosition.x = Mathf.Lerp(transform.position.x, enemy.transform.position.x, Time.deltaTime * speed);
            transform.position = newPosition;
        }
    }
    */
    
    /*
    public float speed = 2.0f;
    private GameObject enemy;
    void OnTriggerEnter2D(Collider2D other)
    {
        if (other.CompareTag("Enemy"))
        {
            enemy = other.gameObject;
        }
    }
    void Update()
    {
        if (enemy != null)
        {
            Vector3 newPosition = transform.position;
            //newPosition.x = Mathf.Lerp(transform.position.x, enemy.transform.position.x, Time.deltaTime * speed);
            transform.position = newPosition;
            transform.rotation = Quaternion.LookRotation(Vector3.forward, enemy.transform.position - transform.position);
        }
    }
    */
    
    public float speed = 2.0f;
    public GameObject bulletPrefab;
    public float bulletSpeed = 10.0f;
    public float fireRate = 0.5f;
    private GameObject _enemy;
    private float _fireTimer = 0f;
    private bool _isenemyNotNull;
    
    
    void OnTriggerEnter2D(Collider2D other)
    {
        if (other.gameObject.CompareTag("Enemy"))
        {
            _enemy = other.gameObject;                               // *** burası önemli ***
            _isenemyNotNull = _enemy != null;
        }
    }
    
    //private void OnCollisionEnter2D(Collision2D other)
    //{
    //    if (other.gameObject.CompareTag("Enemy"))
    //    {
    //        Debug.Log("tagged : zemin");
    //        GetComponent<Rigidbody2D>().velocity = Vector2.zero;
    //    }
    //}

    void Update()
    {
        if (_isenemyNotNull)
        {
            Vector3 newPosition = transform.position;
            //newPosition.x = Mathf.Lerp(transform.position.x, _enemy.transform.position.x, Time.deltaTime * speed);
            transform.position = newPosition;
            transform.rotation = Quaternion.LookRotation(Vector3.forward, _enemy.transform.position - transform.position);
            _fireTimer -= Time.deltaTime;
            if (_fireTimer <= 0)
            {
                _fireTimer = fireRate;
                GameObject bullet = Instantiate(bulletPrefab, transform.position, transform.rotation);
                bullet.GetComponent<Rigidbody2D>().velocity = (_enemy.transform.position - transform.position).normalized * bulletSpeed;
            }
            
        }
        
    }
    
}



