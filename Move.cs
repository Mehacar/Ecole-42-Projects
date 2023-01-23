using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UIElements;
using Cursor = UnityEngine.UIElements.Cursor;

public class Move : MonoBehaviour
{
    private Rigidbody2D _rigidbody2D;
    private Animator _animator;
    private Transform _transform;
    private GameObject _wall;
    

    [SerializeField] public float speed = 5f;
    public float rotationSpeed = 1f;
    private float targetRotation;
    private bool rotating = false;
    private bool vectorrotating = false;

    private bool GameStarted;
    private bool started;
    public static bool turnstate;

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
            //Debug.Log("taggedd");
            rotating = true; //_transform.rotation = Quaternion.Euler(0, 0, -90);
            _wall = other.gameObject;
        }
    }



    private void Update()
    {
        _animator.SetBool("GameStarted", true);
        if (rotating)
        {
            //Debug.Log("rot ture");
            float currentRotation = _transform.eulerAngles.z;
            if (currentRotation <= 360f && currentRotation >= 270f)
            {
                targetRotation = -90f;
                float newRotation = Mathf.Lerp(currentRotation, targetRotation, rotationSpeed * Time.deltaTime);
                _transform.rotation = Quaternion.Euler(0, 0, newRotation);
                turnstate = true;
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
            if (currentRotation <= 360f && currentRotation >= 270f)
            {
                _rigidbody2D.velocity = new Vector2(speed, _rigidbody2D.velocity.y);
            }
            else if (currentRotation < 270f && currentRotation >= 180f)
            {
                _rigidbody2D.velocity = new Vector2(0, -speed);
            }
            //else if (currentRotation < 180f && currentRotation >= 90f)
            //{
            //    _rigidbody2D.velocity = new Vector2(-speed, 0);
            //}
        }
        //if (Input.GetTouch())
        //{
        //    _rigidbody2D.velocity = new Vector2(speed, _rigidbody2D.velocity.y);
        //}
    }
    
}    

