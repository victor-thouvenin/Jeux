using UnityEngine;

public class obstacle_movement : MonoBehaviour
{
    public GameObject self;
    public float speed;
    float move;

    void Start()
    {
        speed = 4;
    }

    void Update()
    {
        move = -speed/transform.localScale.x * Time.deltaTime;
        transform.Translate(move, 0, 0);
        if (transform.position.x < -10)
        {
            Destroy(self);
        }
    }

    void OnCollisionEnter2D(Collision2D col)
    {
        if (col.transform.CompareTag("Player"))
        {
            player blue = col.transform.GetComponent<player>();
            blue.takeDamage();
            Destroy(self);
        }
    }

}
