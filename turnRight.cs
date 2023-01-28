using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UIElements;
using Cursor = UnityEngine.UIElements.Cursor;

public class turnRight : MonoBehaviour
{
    private Rigidbody2D _rigidbody2D;
    private Animator _animator;
    private Transform _transform;
    
    [SerializeField] public float speed = 5f;
    public float rotationSpeed = 1f;
    private float targetRotation;
    private bool rotating = false;
    private bool vectorrotating = false;
    
    private bool GameStarted;
    private bool started;
    private void Awake()
    {
        _rigidbody2D = GetComponent<Rigidbody2D>(); // caching (remde hızlıca bulabilmek için ön yükleme işlemi)
        _animator = GetComponent<Animator>();
        _transform = GetComponent<Transform>();
        started = true;
        vectorrotating = true;
    }

    private void OnTriggerEnter2D(Collider2D other)
    {
        if (other.gameObject.CompareTag("Tagged"))
        {
            rotating = true;
            
        }
    }
    


    private void Update()
    {
        _animator.SetBool("GameStarted", true);
        if (rotating)
        {
            float currentRotation = _transform.eulerAngles.z;
            if (currentRotation <= 270f && currentRotation >= 180f)
            {
                targetRotation = -180f;
                float newRotation = Mathf.Lerp(currentRotation, targetRotation, rotationSpeed * Time.deltaTime);
                _transform.rotation = Quaternion.Euler(0, 0, newRotation);
                //Debug.Log("finish rotate");
            }
            else
            {
                rotating = false;
            }
        }
    }

    private void FixedUpdate()
    {
        if (vectorrotating)
        {
            float currentRotation = _transform.eulerAngles.z;
            if (currentRotation < 180f && currentRotation >= 90f)
            {
                _rigidbody2D.velocity = new Vector2(-speed, 0);
            }
        }
    }
}
