using UnityEngine;

public class player : MonoBehaviour
{
    public GameObject hole;
    public GameObject sprite;

    float posX = 0f;
    float posY = 0f;
    float moveX = 0;
    float moveY = 0f;
    float maxMove = 4.2f;

    Vector3 pos;
    float distance;
    float damage = 0f;
    float health = 255f;
    void Start()
    {
        Cursor.visible = false;
    }

    void Update()
    {
        moveY = Input.GetAxis("Mouse Y");
        if (posY+moveY > -maxMove && posY+moveY <= maxMove)
        {
            posY += moveY/2;
        }
        if (moveX < -.0001)
        {
            posX += moveX*Time.deltaTime;
            moveX -= moveX*Time.deltaTime;
        }
        distance = Vector2.Distance(transform.position, hole.transform.position) -12;
        if (distance < 5f && health > 0)
        {
            getDamage();
        }
        if (health <= 0)
        {
            gameOver();
        }
    }

    void FixedUpdate()
    {
        pos = new Vector2 (posX, posY);
        if (posY > -maxMove && posY < maxMove)
        {
            transform.position = pos;
        }
    }

    void getDamage()
    {
        SpriteRenderer renderer;
        damage += (5f-distance)*Time.deltaTime;
        if (damage >= 1f)
        {
            health -= 1f;
            damage -= 1f;
            renderer = sprite.GetComponent<SpriteRenderer>();
            renderer.color = new Color (0, 0, health/255f);
        }
    }

    public void takeDamage()
    {
        health -= 5f;
        moveX -= .5f;
    }

    void gameOver()
    {
    }
}
