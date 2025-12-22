using UnityEngine;

public class obstacle_creation : MonoBehaviour
{
    public GameObject obstacle;
    public GameObject container;
    public float size = 1;
    float posY = 0;
    float clock;

    void Start()
    {
    }

    void Update()
    {
        clock += Time.deltaTime;
        if (clock >= size)
        {
            posY = Random.Range(-5f, 5f);
            createObstacle(size);
            clock -= size;
            size = Random.Range(.5f, 3f);
        }
    }

    void createObstacle(float size)
    {
        GameObject clone = Instantiate(obstacle, new Vector3(transform.position.x, posY, 0), transform.rotation);
        clone.transform.parent = container.transform;
        clone.transform.localScale = new Vector3(size, size, 0);
    }
}
