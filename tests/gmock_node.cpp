#include "node.h"

class MockNode : public Node {
public:
    MOCK_METHOD(void, setNext, (Node* nextNode), (override));
    MOCK_METHOD(Node*, getNext, (), (const, override));
};

TEST(MockNodeTest, SetNextTest) {
    MockNode mockNode;
    MockNode mockNextNode;
    EXPECT_CALL(mockNode, setNext(&mockNextNode));
    mockNode.setNext(&mockNextNode);
}

TEST(MockNodeTest, GetNextTest) {
    MockNode mockNode;
    MockNode mockNextNode;
    EXPECT_CALL(mockNode, getNext()).WillOnce(::testing::Return(&mockNextNode));
    Node* nextNode = mockNode.getNext();
    ASSERT_EQ(nextNode, &mockNextNode);
}